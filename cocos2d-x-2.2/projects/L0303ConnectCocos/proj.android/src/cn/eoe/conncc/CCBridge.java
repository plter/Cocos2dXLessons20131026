package cn.eoe.conncc;

import android.content.Context;
import android.os.Handler;
import android.os.Message;
import android.widget.Toast;

public class CCBridge {

	public static void init(Context context){
		CCBridge.context = context;
		
		initNative();
	}
	
	public static Context getContext() {
		return context;
	}
	
	public static void showToast(String msg){
		
		Message androidMsg = new Message();
		androidMsg.obj = msg;
		showToastHandler.sendMessage(androidMsg);
	}
	
	public static native void initNative();
	
	
	private static Context context=null;
	
	private static final Handler showToastHandler = new Handler(){
		public void handleMessage(android.os.Message msg) {
			Toast.makeText(getContext(), msg.obj.toString(), Toast.LENGTH_SHORT).show();
		};
	};
}
