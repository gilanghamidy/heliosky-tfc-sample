/*
 * Heliosky.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: Gilang M. Hamidy (g.hamidy@samsung.com)
 */

#include "Heliosky.h"

#include "Controller/SplashScreenController.h"
#include "Controller/MainAppController.h"

HelioskyAppClass HelioskyApp;

HelioskyAppClass::HelioskyAppClass() :
	TFC::Framework::MVCApplicationBase(PACKAGE, /* Start up controller */ CONTROLLER_SPLASHSCREEN)
{
	// Registrer controller class here
	RegisterController(CONTROLLER_SPLASHSCREEN, /* Controller name definition*/
					   Heliosky::Controller::SplashScreenController /* Class of the controller */);

	RegisterController(CONTROLLER_MAINAPP, Heliosky::Controller::MainAppController);
}

void HelioskyAppClass::OnApplicationCreated()
{
	defaultTheme = elm_theme_new();
	elm_theme_ref_set(defaultTheme, elm_theme_default_get());

	auto path = TFC::Framework::ApplicationBase::GetResourcePath("edc/overlay/naviframe.edj");
	elm_theme_overlay_add(defaultTheme, path.c_str());

	elm_object_theme_set(this->rootFrame, defaultTheme);

	// This method is called after the application is created but before the first controller is loaded
	// Alwasy call base class implementation when overriding this method
	MVCApplicationBase::OnApplicationCreated();
}

int main(int argc, char** argv)
{
	// Always call Framework Main
	return TFC::Framework::ApplicationBase::Main(&HelioskyApp, argc, argv);
}

HelioskyException::HelioskyException(const std::string& message) : msg(message)
{

}

HelioskyException::~HelioskyException()
{

}

const char* HelioskyException::what() const
{
	return msg.c_str();
}
