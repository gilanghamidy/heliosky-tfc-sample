/*
 * SplashScreenController.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: Gilang M. Hamidy (g.hamidy@samsung.com)
 */

#include "Controller/SplashScreenController.h"
#include <chrono>
#include <thread>

Heliosky::Controller::SplashScreenController::SplashScreenController(TFC::Framework::ControllerManager* m) :
	TFC::Framework::ControllerBase( /* Call base constructor to pass information to it */
		m, 						/* Pass the parameter to parent */
		&splashScreenView, 		/* The view for this controller */
		CONTROLLER_SPLASHSCREEN /* The name of this controller */)
{

}

void Heliosky::Controller::SplashScreenController::OnLoad(TFC::ObjectClass* param)
{
	// Perform some kind of loading, but actually it is just a delay
	// using TFC Asynchronous Library

	// tfc_async keyword defines an asynchronous operation which will executes the following
	// lambda method in threadpool
	tfc_async
	{
		// Just doing some sleep
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
	tfc_async_complete
	{
		this->Manager->NavigateTo(CONTROLLER_MAINAPP, nullptr, true);
	};
}


TFC::ObjectClass* Heliosky::Controller::SplashScreenController::OnUnload()
{
	// Return anything to previous controller who load this controller
	return nullptr;
}
