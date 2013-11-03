#include <wrl/client.h>
#include <d3d11_1.h>
#include <DirectXMath.h>
#include <memory>
#include <agile.h>
#include <ppltasks.h>
#include "L0308InputText.h"
#include "CCApplication.h"

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;
using namespace Windows::Phone::UI::Input;
using namespace Windows::Graphics::Display;
using namespace concurrency;
USING_NS_CC;

L0308InputText::L0308InputText()
{
}

void L0308InputText::Initialize(CoreApplicationView^ applicationView)
{
	applicationView->Activated +=
		ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &L0308InputText::OnActivated);

	CoreApplication::Suspending +=
		ref new EventHandler<SuspendingEventArgs^>(this, &L0308InputText::OnSuspending);

	CoreApplication::Resuming +=
		ref new EventHandler<Platform::Object^>(this, &L0308InputText::OnResuming);
}

void L0308InputText::SetWindow(CoreWindow^ window)
{
    // Specify the orientation of your application here
    // The choices are DisplayOrientations::Portrait or DisplayOrientations::Landscape or DisplayOrientations::LandscapeFlipped
	DisplayProperties::AutoRotationPreferences = DisplayOrientations::Landscape;

	window->VisibilityChanged +=
		ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &L0308InputText::OnVisibilityChanged);

	window->Closed += 
		ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &L0308InputText::OnWindowClosed);

	window->PointerPressed +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &L0308InputText::OnPointerPressed);

	window->PointerMoved +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &L0308InputText::OnPointerMoved);

	window->PointerReleased +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &L0308InputText::OnPointerReleased);

    CCEGLView* eglView = new CCEGLView();
	eglView->Create(window);
    eglView->setViewName("L0308InputText");
}

void L0308InputText::Load(Platform::String^ entryPoint)
{
}

void L0308InputText::Run()
{
    CCApplication::sharedApplication()->run();
}

void L0308InputText::Uninitialize()
{
}

void L0308InputText::OnVisibilityChanged(CoreWindow^ sender, VisibilityChangedEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnVisibilityChanged(sender, args);
}

void L0308InputText::OnWindowClosed(CoreWindow^ sender, CoreWindowEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnWindowClosed(sender, args);
}

void L0308InputText::OnPointerPressed(CoreWindow^ sender, PointerEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnPointerPressed(sender, args);
}

void L0308InputText::OnPointerMoved(CoreWindow^ sender, PointerEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnPointerMoved(sender, args);
}

void L0308InputText::OnPointerReleased(CoreWindow^ sender, PointerEventArgs^ args)
{
	CCEGLView::sharedOpenGLView()->OnPointerReleased(sender, args);
}

void L0308InputText::OnActivated(CoreApplicationView^ applicationView, IActivatedEventArgs^ args)
{
	HardwareButtons::BackPressed += ref new EventHandler<BackPressedEventArgs^>(this, &L0308InputText::OnBackButtonPressed);   
	CoreWindow::GetForCurrentThread()->Activate();
}

void L0308InputText::OnBackButtonPressed(Object^ sender, BackPressedEventArgs^ args)
{
    // Leave args->Handled set to false and the app will quit when user presses the back button on the phone
}

void L0308InputText::OnSuspending(Platform::Object^ sender, SuspendingEventArgs^ args)
{
	// Save app state asynchronously after requesting a deferral. Holding a deferral
	// indicates that the application is busy performing suspending operations. Be
	// aware that a deferral may not be held indefinitely. After about five seconds,
	// the app will be forced to exit.
	SuspendingDeferral^ deferral = args->SuspendingOperation->GetDeferral();
	//m_renderer->ReleaseResourcesForSuspending();

	create_task([this, deferral]()
	{
		// Insert your code here.

		deferral->Complete();
	});
}
 
void L0308InputText::OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
	// Restore any data or state that was unloaded on suspend. By default, data
	// and state are persisted when resuming from suspend. Note that this event
	// does not occur if the app was previously terminated.
	// m_renderer->CreateWindowSizeDependentResources();
}

IFrameworkView^ Direct3DApplicationSource::CreateView()
{
	return ref new L0308InputText();
}

[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
	auto direct3DApplicationSource = ref new Direct3DApplicationSource();
	CoreApplication::Run(direct3DApplicationSource);
	return 0;
}