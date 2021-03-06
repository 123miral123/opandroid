package com.openpeer.openpeernativesampleapp;

import android.util.Log;

import com.openpeer.delegates.CallbackHandler;
import com.openpeer.delegates.OPAccountDelegateImplementation;
import com.openpeer.delegates.OPIdentityDelegateImplementation;
import com.openpeer.javaapi.OPAccount;
import com.openpeer.javaapi.OPAccountDelegate;
import com.openpeer.javaapi.OPIdentity;
import com.openpeer.javaapi.OPIdentityDelegate;
import com.openpeer.javaapi.OPStack;
import com.openpeer.javaapi.OPStackMessageQueue;

public class LoginManager {

	public static void LoginWithFacebook (){
		//TODO: Add delegate when implement mechanism to post events to the android GUI thread
		//stackMessageQueue = OPStackMessageQueue.singleton(); 
		//stackMessageQueue = new OPStackMessageQueue();
		//stackMessageQueue.interceptProcessing(null);
		
		//TODO: After interception is done, we can call setup
//		stack = new OPStack();
//		stack.setup(null, null, "bojan", "bojan1", "bojan2", "bojan3", "bojan4", "bojan5", "bojan6", "bojan7");
		
//		LoginManager.stackMessageQueue = new OPStackMessageQueue();
//		LoginManager.stackMessageQueue.interceptProcessing(null);
		LoginManager.stack = new OPStack();
		LoginManager.stack.setup(null, null, "bojan", "bojan1", "bojan2", "bojan3", "bojan4", "bojan5", "bojan6", "bojan7");
		
		//prepare account delegate
		mAccountDelegate = new OPAccountDelegateImplementation();
		mAccount = new OPAccount();
		//register delegates and class for callback from native code
		CallbackHandler.registerAccountDelegate(mAccount, mAccountDelegate);
		
		
		mIdentityDelegate = new OPIdentityDelegateImplementation();
		mIdentity = new OPIdentity();
		CallbackHandler.registerIdentityDelegate(mIdentity, mIdentityDelegate);
		//TODO: Now we can start login procedure
		OPAccount.login(null, null, null, null, null, null, null, null, null);//delegate, conversationThreadDelegate, callDelegate, namespaceGrantOuterFrameURLUponReload, namespaceGrantServiceDomain, grantID, grantSecret, lockboxServiceDomain, forceCreateNewLockboxAccount)
		
		OPIdentity.login(mAccount, mIdentityDelegate, "idprovider-javascript.hookflash.me", "identity://idprovider-javascript.hookflash.me/", "https://app-javascript.hookflash.me/outer.html?reload=true");
	}
	
	
	
	public static OPAccount getAccount() {
		return mAccount;
	}
	public static void setAccount(OPAccount account) {
		LoginManager.mAccount = account;
	}

	public static OPStack stack;
	public static OPStackMessageQueue stackMessageQueue;
	public static OPAccount mAccount;
	public static OPAccountDelegate mAccountDelegate;
	public static OPIdentity mIdentity;
	public static OPIdentityDelegate mIdentityDelegate;
	static LoginHandlerInterface mLoginHandler;
	
	public static void setHandlerListener(LoginHandlerInterface listener)
   {
	   mLoginHandler=listener;
   }
	
	public static void loadOuterFrame() {
		// TODO Auto-generated method stub
		
		   
		   
      //if(mLoginHandler!=null)
    	  //mLoginHandler.onLoadOuterFrameHandle(null);
		
	}
	
	public static void startIdentityLogin() {
		// TODO Auto-generated method stub
		
		   
		   
      if(mLoginHandler!=null)
    	  mLoginHandler.onLoadOuterFrameHandle(null);
		
	}
}
