package cn.eoe.hellojni;

public class JNI {

	public native int getNum();
	
	public native int max(int a,int b);
	
	public native String getString();
	
	public static native void sayHi();
	
	public int getInt(){
		return 8;
	}
	
	static{
		System.loadLibrary("HelloJNI");
	}
}
