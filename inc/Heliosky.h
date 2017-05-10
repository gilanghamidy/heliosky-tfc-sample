/*
 * Heliosky.h
 *
 *  Created on: Apr 11, 2016
 *      Author: Gilang M. Hamidy (g.hamidy@samsung.com)
 */

#ifndef HELIOSKY_H_
#define HELIOSKY_H_

#include "TFC/Framework/Application.h"
#include "TFC/Framework/MVCApplication.h"

#ifdef  LOG_TAG
#undef  LOG_TAG
#endif
#define LOG_TAG "Heliosky-App"

#if !defined(PACKAGE)
#define PACKAGE "com.heliosky.tizen"
#endif


#define RAPIDJSON_HAS_STDSTRING 1

// Define controller name here. This is to identify controller without having to load the entire class header
#define CONTROLLER_SPLASHSCREEN		"SplashScreenController"
#define CONTROLLER_MAINAPP			"MainAppController"
#define CONTROLLER_POSTLIST			"PostListController"
#define CONTROLLER_POST				"PostController"

class HelioskyAppClass : public TFC::Framework::MVCApplicationBase
{
private:
	// Handle to elementary theme
	Elm_Theme* defaultTheme;
public:
	HelioskyAppClass();
	virtual void OnApplicationCreated();
	~HelioskyAppClass() { };
};

extern HelioskyAppClass HelioskyApp;

#include <exception>
#include <string>

class HelioskyException : public std::exception {
public:
	HelioskyException(std::string const &message);
	virtual ~HelioskyException();
	virtual char const* what() const noexcept;
private:
	std::string msg;
};


#endif /* CNNINDONESIA_H_ */
