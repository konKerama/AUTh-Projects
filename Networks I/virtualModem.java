import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

import ithakimodem.Modem;

public class virtualModem {
	public static void main(String[] param) {
		(new virtualModem()).demo();
	}
	
	public void demo() {
		String echo="E4010\r";
		String image="M1253\r";
		String imageError="G3680\r";
		String gps="P0183";
		String ack="Q1824\r";
		String nack="R1197\r";
			
		echoRequestCode(echo);		
		imageRequestCode(image);
		gpsSignal(gps);
		imageWithErrorsRequestCode(imageError);
		ackCode(ack,nack);
	}
	
	static void echoRequestCode(String echo){
		int k;
		
		Modem modem;
		modem=new Modem();
		modem.setSpeed(8000);
		modem.setTimeout(2000);
		modem.open("ithaki");
		
		for (;;) {
			try {
				k=modem.read();
				if (k==-1) break;
				System.out.print((char)k);
			} catch (Exception x) {
				break;
			}
		}
		
		
		
		
		String message;
		message="";
		int a;
		System.out.println("Echo");
		String finaliser="PSTOP";
		long t1,t2,dt;
		
		FileOutputStream writer = null;
		try {
			writer = new FileOutputStream("C:\\Users\\Kostas\\Desktop\\echo.txt");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		long start=System.currentTimeMillis();
		long end=System.currentTimeMillis();
		
		System.out.println("Start of Reading");
		for(;;){
			t1=System.currentTimeMillis();
			modem.write(echo.getBytes());
			
			for (;;) {
				a=modem.read();
				message+=(char)a;
				if ( message.toLowerCase().indexOf(finaliser.toLowerCase()) != -1 ){
					t2=System.currentTimeMillis();
					break;
				}
			}
			dt=t2-t1;
			try {
				writer.write((Long.toString(dt)).getBytes());
				writer.write(System.getProperty("line.separator").getBytes());
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			System.out.println("Time: "+dt);
			System.out.println(message);
			message="";
			end=System.currentTimeMillis();
			if ((end-start)>=240000){
				break;
			}
		}
		System.out.println("End of Reading");
		modem.close();
	}
	
	static void imageRequestCode(String image){
		int k;
		
		Modem modem;
		modem=new Modem();
		modem.setSpeed(8000);
		modem.setTimeout(2000);
		modem.open("ithaki");
		
		for (;;) {
			try {
				k=modem.read();
				if (k==-1) break;
				System.out.print((char)k);
			} catch (Exception x) {
				break;
			}
		}
		
		System.out.println("\nImage");
		System.out.println("Start of Reading");
		modem.write(image.getBytes());
		try{
			FileOutputStream writer = new FileOutputStream("C:\\Users\\Kostas\\Desktop\\image.png");
		   	for(;;){
				k=modem.read();
				writer.write((byte)k);
				if (k==-1){
					System.out.println("End of Reading");
					break;
				}
			}
		    writer.close();
		}catch (Exception e){
			System.out.print("Exception Image");
		}
		modem.close();
	}
	
	static void gpsSignal(String gps){
		int k;
		
		Modem modem;
		modem=new Modem();
		modem.setSpeed(8000);
		modem.setTimeout(2000);
		modem.open("ithaki");
		
		for (;;) {
			try {
				k=modem.read();
				if (k==-1) break;
				System.out.print((char)k);
			} catch (Exception x) {
				break;
			}
		}
		
		String[] partsA,partsD;
		//String partA1,partA2,partD1,partD2;
		int[] AAPart1= new int[99];
		int[] AAPart2= new int[99];
		int[] DDPart1= new int[99];
		int[] DDPart2= new int[99];
		int tCounter=0;
		String tString="";
		System.out.println("\nGPS signal");
		modem.write((gps+"R=1003099\r").getBytes());
		int counter=0;
		int flag=0;
		String AABBGG="";
		String DDEEZZ="";
		for(;;){
			k=modem.read();
			if(flag==0){
				if((char)k=='\r')flag=1;				
			}
			if(flag==1){
				if((counter>19)&&(counter<=28)){
					AABBGG+=(char)k;
				}
				if((counter>31)&&(counter<=41)){
					DDEEZZ+=(char)k;
				}
				if((counter!=0)&&((char)k=='\r')&&(counter>70)){
					
					System.out.println("\n"+ "/--------------------------------------/");
					System.out.println("a)"+AABBGG);
					System.out.println("b)"+DDEEZZ);
					System.out.println("tc="+tCounter);
					partsA=AABBGG.split("\\.");
					AAPart1[tCounter] = Integer.parseInt(partsA[0]);
					int tempA=Integer.parseInt(partsA[1]);
					//System.out.println(partA1);
					AAPart2[tCounter]=(int)(tempA*(0.006));
					
					partsD=DDEEZZ.split("\\.");
					DDPart1[tCounter] = Integer.parseInt(partsD[0]);
					int tempD=Integer.parseInt(partsD[1]);
					//System.out.println(partD1);
					DDPart2[tCounter]=(int)(tempD*(0.006));
					
					//tString=gps+"T="+partD1+partD2+partA1+partA2+"\r";
					//System.out.println("t"+tString);

					tCounter++;
					AABBGG="";
					DDEEZZ="";
					counter=0;
				}
				counter++;
			}
			System.out.print((char)k);
			
			if (k==-1)break; 
			
		}
		tString=gps;
		for (int i=0;i<AAPart1.length;i+=10){
			
			tString+="T="+(Integer.toString(DDPart1[i]))+(Integer.toString(DDPart2[i]))+(Integer.toString(AAPart1[i]))+(Integer.toString(AAPart2[i]));
		}
		tString+="\r";
		System.out.println("d1 "+DDPart1[0]);
		System.out.println("d2 "+DDPart2[0]);
		System.out.println("a1 "+AAPart1[0]);
		System.out.println("a2 "+AAPart2[0]);
		System.out.println(tString);
		
		//Image
		System.out.println("\nGPS Image");
		System.out.println("Start of Reading");
		modem.write(tString.getBytes());
		try{
			FileOutputStream writer = new FileOutputStream("C:\\Users\\Kostas\\Desktop\\GPSimage.png");
			for(;;){
				k=modem.read();
				writer.write((byte)k);
				if (k==-1){
					System.out.println("End of Reading");
					break;
				}
			}
			writer.close();
		}catch (Exception e){
			System.out.print("Exception Image");
		}
		
		modem.close();
	}
	
	static void imageWithErrorsRequestCode(String imageError){
		int k;
		Modem modem;
		modem=new Modem();
		modem.setSpeed(8000);
		modem.setTimeout(2000);
		modem.open("ithaki");
		
		for (;;) {
			try {
				k=modem.read();
				if (k==-1) break;
				System.out.print((char)k);
			} catch (Exception x) {
				break;
			}
		}
		
		System.out.println("\nImage with Errors");
		System.out.println("Start of Reading");
		modem.write(imageError.getBytes());
		try{
			FileOutputStream writer = new FileOutputStream("C:\\Users\\Kostas\\Desktop\\imageError.png");
			for(;;){
				k=modem.read();
				writer.write((byte)k);
				if (k==-1){
					System.out.println("End of Reading");
					break;
				}
			}
			writer.close();
		}catch (Exception e){
			System.out.print("Exception Image");
		}
	}
	
	static void ackCode(String ack,String nack){
		boolean flagError=true;
		int k;
		
		Modem modem;
		modem=new Modem();
		modem.setSpeed(8000);
		modem.setTimeout(2000);
		modem.open("ithaki");
		
		for (;;) {
			try {
				k=modem.read();
				if (k==-1) break;
				System.out.print((char)k);
			} catch (Exception x) {
				break;
			}
		}
		
		int errorCounter=0;
		int numOfPackage=0;
		System.out.println("Ack/Nack Code");
		String message="";
		String code=ack;
		long packetStart=0;
		long packetFinish;
		long packetTime;
		long start=System.currentTimeMillis();
		long end = 0;
		String finaliser="PSTOP";
		
		FileOutputStream writer=null;
		try {
			writer = new FileOutputStream("C:\\Users\\Kostas\\Desktop\\arq.txt");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		try {
			writer.write("PID".getBytes());
			writer.write("\t".getBytes());
			writer.write("Dur".getBytes());
			writer.write("\t".getBytes());
			writer.write("Errors".getBytes());
			writer.write(System.getProperty("line.separator").getBytes());
		} catch (IOException e) {
			e.printStackTrace();
		}

		System.out.println("Start of Reading");
		for(;;){	
			
			if (flagError==true){
				errorCounter=0;
				packetStart=System.currentTimeMillis();
			}else{
				errorCounter++;
			}
			message="";
			modem.write(code.getBytes());
			for (;;) {
				try {
					k=modem.read();
					message+=(char)k;
					if (message.toLowerCase().indexOf(finaliser.toLowerCase()) != -1){
						break;
					}
					System.out.print((char)k);
				} catch (Exception x) {
					break;
				}
					
			}
			
			if (Arq(message)==true){
				code=ack;
				packetFinish=System.currentTimeMillis();
				packetTime=packetFinish-packetStart;
				numOfPackage++;
				System.out.println(numOfPackage+" "+packetTime+" "+errorCounter);
				flagError=true;
				
				try {
					writer.write((Integer.toString(numOfPackage)).getBytes());
					writer.write("\t".getBytes());
					writer.write((Long.toString(packetTime)).getBytes());
					writer.write("\t".getBytes());
					writer.write((Integer.toString(errorCounter)).getBytes());
					writer.write(System.getProperty("line.separator"). getBytes());
				} catch (IOException e) {	 	 	 	 	
					e.printStackTrace();
				}
				
				//print in file
				
			}else{
				flagError=false;
				code=nack;
			}
			
			end=System.currentTimeMillis();
			long duration=end-start;
			
			if (duration>=240000){
				break;
			}
		
		}
		System.out.println("End of Reading");
		modem.close();
		
	}
	
	static boolean Arq(String message){
		char[] sequence=new char[16];
		char[] charFCS = new char[3];
		
		int j=0;
		for(int i=31;i<47;i++){
			sequence[j]=message.charAt(i);
			j++;
		}
		j=0;
		for(int i=49;i<52;i++){
			charFCS[j]=message.charAt(i);
			j++;
		}
		StringBuilder result;
		
		result = new StringBuilder(3);
		for(Character c : charFCS){
			result.append(c);
		}
		String strResult= result.toString();
		Integer FCS = Integer.parseInt(strResult);
		Integer xor;
		
		xor=sequence[0]^sequence[1];
		for (int i=2;i<16;i++){
			xor^=sequence[i];
		}
		if (xor==FCS){
			System.out.println("\nACK");
			return true;
		}else{
			System.out.println("\nNACK");
			return false;
		}
	}
	
}
