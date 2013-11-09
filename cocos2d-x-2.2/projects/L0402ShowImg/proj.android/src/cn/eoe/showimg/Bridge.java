package cn.eoe.showimg;

public class Bridge {

	public static native void showImg(String imgName);
	public static native void init();
	
	public static void onInit(){
		
		if (getOnBridgeInitListener()!=null) {
			getOnBridgeInitListener().onInit();
		}
	}
	
	public static OnBridgeInitListener getOnBridgeInitListener() {
		return onBridgeInitListener;
	}
	
	
	public static void setOnBridgeInitListener(
			OnBridgeInitListener onBridgeInitListener) {
		Bridge.onBridgeInitListener = onBridgeInitListener;
	}
	
	private static OnBridgeInitListener onBridgeInitListener = null;
}
