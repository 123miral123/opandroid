package com.openpeer.delegates;

import com.openpeer.javaapi.IdentityStates;
import com.openpeer.javaapi.OPIdentity;
import com.openpeer.javaapi.OPIdentityDelegate;
import com.openpeer.openpeernativesampleapp.LoginManager;

public class OPIdentityDelegateImplementation extends OPIdentityDelegate{

	@Override
	public void onIdentityStateChanged(OPIdentity identity, IdentityStates state) {
		// TODO Auto-generated method stub
		switch (state){
		case IdentityState_WaitingForBrowserWindowToBeLoaded:
			LoginManager.loadOuterFrame();
		}
		
	}

	@Override
	public void onIdentityPendingMessageForInnerBrowserWindowFrame(
			OPIdentity identity) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void onIdentityRolodexContactsDownloaded(OPIdentity identity) {
		// TODO Auto-generated method stub
		
	}

}
