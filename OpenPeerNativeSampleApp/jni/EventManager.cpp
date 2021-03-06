#include "EventManager.h"
#include "globals.h"
#include "com_openpeer_javaapi_OPStackMessageQueue.h"

//IStackMessageQueueDelegate implementation
void EventManager::onStackMessageQueueWakeUpCustomThreadAndProcessOnCustomThread()
	{
		jclass cls;
		jmethodID method;
		jobject object;
		JNIEnv *jni_env = 0;

		jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
		if (attach_result < 0 || jni_env == 0)
		{
		   return;
		}
		//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
		method = jni_env->GetMethodID(gCallbackClass, "onJniCallback", "()V");
		jni_env->CallVoidMethod(gCallbackClass, method);

		if (jni_env->ExceptionCheck()) {
			jni_env->ExceptionDescribe();
		}

		android_jvm->DetachCurrentThread();

		IStackMessageQueue::singleton()->notifyProcessMessageFromCustomThread();
	}

//IStackDelegate implementation
void EventManager::onStackShutdown(openpeer::core::IStackAutoCleanupPtr)
{
	int i = 0;
	i++;
}

//IMediaEngine implementation
void EventManager::onMediaEngineAudioRouteChanged(openpeer::core::IMediaEngine::OutputAudioRoutes audioRoute)
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onMediaEngineAudioRouteChanged", "(I)V");
	jni_env->CallVoidMethod(gCallbackClass, method, (jint) audioRoute);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();

}
void EventManager::onMediaEngineFaceDetected()
{

	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onMediaEngineFaceDetected", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::onMediaEngineVideoCaptureRecordStopped()
{

	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onMediaEngineVideoCaptureRecordStopped", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}

//IAccountDelegate implementation
void EventManager::onAccountStateChanged(IAccountPtr account, IAccount::AccountStates state)
{

	jclass cls;
	jmethodID method;
	jobject object;
	//JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&gEnv, NULL);
	if (attach_result < 0 || gEnv == 0)
	{
	   return;
	}

	jclass callbackClass = findClass("com/openpeer/delegates/CallbackHandler");
	method = gEnv->GetStaticMethodID(callbackClass, "onAccountStateChanged", "(I)V");
	gEnv->CallStaticVoidMethod(callbackClass, method, (jint) state);

	if (gEnv->ExceptionCheck()) {
		gEnv->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
	/*
	jint attach_result = android_jvm->AttachCurrentThread(&gEnv, NULL);
	if (attach_result < 0 || gEnv == 0)
	{
	   return;
	}

	// get the callback handler class
	  //javaCallbackHandlerFields.callbackHandlerClass = (jclass) env->NewGlobalRef(env->FindClass(_kClassPathCallbackHandler));


	cls = (jclass)gEnv->NewGlobalRef(gEnv->FindClass("com/openpeer/javaapi/OPAccountDelegate"));

	  if (!cls) {
	    //__android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Register: failed to get class for: %s", _kClassPathCallbackHandler);
	    return;
	  }
	jmethodID constr = gEnv->GetMethodID(cls,
		      "<init>","()V");
	jobject delegate = gEnv->NewObject(
			cls,
			constr);


	method = gEnv->GetMethodID(cls, "onAccountStateChanged", "(Lcom/openpeer/javaapi/OPAccount;Lcom/openpeer/javaapi/AccountStates;)V");
	gEnv->CallVoidMethod(delegate, method, NULL, NULL);

	//IStackMessageQueue::singleton()->notifyProcessMessageFromCustomThread();
*/


}
void EventManager::onAccountAssociatedIdentitiesChanged(IAccountPtr account)
{

	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onAccountAssociatedIdentitiesChanged", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::onAccountPendingMessageForInnerBrowserWindowFrame(IAccountPtr account)
{

	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onAccountPendingMessageForInnerBrowserWindowFrame", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}

//IConversationThreadDelegate implementation
void EventManager::onConversationThreadNew(IConversationThreadPtr conversationThread)
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onConversationThreadNew", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::onConversationThreadContactsChanged(IConversationThreadPtr conversationThread)
{

	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onConversationThreadContactsChanged", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::onConversationThreadContactStateChanged(
	                                                     IConversationThreadPtr conversationThread,
	                                                     IContactPtr contact,
	                                                     IConversationThread::ContactStates state
	                                                     )
{

	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onConversationThreadContactStateChanged", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::onConversationThreadMessage(
	                                         IConversationThreadPtr conversationThread,
	                                         const char *messageID
	                                        )
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onConversationThreadMessage", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::onConversationThreadMessageDeliveryStateChanged(
	                                                             IConversationThreadPtr conversationThread,
	                                                             const char *messageID,
	                                                             IConversationThread::MessageDeliveryStates state
	                                                             )
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onConversationThreadMessageDeliveryStateChanged", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::onConversationThreadPushMessage(
	                                             IConversationThreadPtr conversationThread,
	                                             const char *messageID,
	                                             IContactPtr contact
	                                             )
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onConversationThreadPushMessage", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}

//ICallDelegate implementation
void EventManager::onCallStateChanged(ICallPtr call, ICall::CallStates state)
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onCallStateChanged", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}

//IIdentityDelegate implementation
void EventManager::onIdentityStateChanged(
	                                          IIdentityPtr identity,
	                                          IIdentity::IdentityStates state
	                                          )
{
		jclass cls;
		jmethodID method;
		jobject object;
		//JNIEnv *jni_env = 0;

		jint attach_result = android_jvm->AttachCurrentThread(&gEnv, NULL);
		if (attach_result < 0 || gEnv == 0)
		{
		   return;
		}

		//jclass callbackClass = findClass("com/openpeer/delegates/CallbackHandler");
		method = gEnv->GetStaticMethodID(gCallbackClass, "onIdentityStateChanged", "(I)V");
		gEnv->CallStaticVoidMethod(gCallbackClass, method, (jint) state);

		if (gEnv->ExceptionCheck()) {
			gEnv->ExceptionDescribe();
		}

		android_jvm->DetachCurrentThread();
}
void EventManager::onIdentityPendingMessageForInnerBrowserWindowFrame(IIdentityPtr identity)
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onIdentityPendingMessageForInnerBrowserWindowFrame", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::onIdentityRolodexContactsDownloaded(IIdentityPtr identity)
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onIdentityRolodexContactsDownloaded", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}


//IIdentityLookupDelegate implementation
void EventManager::onIdentityLookupCompleted(
			IIdentityLookupPtr identity
	)
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "onIdentityLookupCompleted", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}

	//ICacheDelegate implementation
zsLib::String EventManager::fetch(const char *cookieNamePath)
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "fetch", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::store(const char *cookieNamePath,
            Time expires,
            const char *str)
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "store", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}
void EventManager::clear(const char *cookieNamePath)
{
	jclass cls;
	jmethodID method;
	jobject object;
	JNIEnv *jni_env = 0;

	jint attach_result = android_jvm->AttachCurrentThread(&jni_env, NULL);
	if (attach_result < 0 || jni_env == 0)
	{
		return;
	}
	//cls = jni_env->FindClass("com/openpeer/delegates/OPStackMessageQueueDelegate");
	method = jni_env->GetMethodID(gCallbackClass, "clear", "()V");
	jni_env->CallVoidMethod(gCallbackClass, method);

	if (jni_env->ExceptionCheck()) {
		jni_env->ExceptionDescribe();
	}

	android_jvm->DetachCurrentThread();
}

EventManager::~EventManager()
{
	int i = 0;
	i++;
}
