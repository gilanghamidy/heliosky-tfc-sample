/*
 * SplashScreenController.h
 *
 *  Created on: Apr 11, 2016
 *      Author: Gilang M. Hamidy (g.hamidy@samsung.com)
 */

#ifndef SPLASHSCREENCONTROLLER_H_
#define SPLASHSCREENCONTROLLER_H_

#include "View/SplashScreenView.h"
#include "TFC/Async.h"

using namespace Heliosky::View;

namespace Heliosky {
	namespace Controller {
		class SplashScreenController: public TFC::Framework::ControllerBase {
		private:
			// Define the view of the controller here
			SplashScreenView splashScreenView;

		public:
			// Controller must have constructor with this exact parameter
			SplashScreenController(TFC::Framework::ControllerManager* m);

			// This method will be called when the controller is loaded by the application
			virtual void OnLoad(TFC::ObjectClass* param);

			// This method will be called before leaving the controller
			virtual TFC::ObjectClass* OnUnload();
		};
	}
}



#endif /* SPLASHSCREENCONTROLLER_H_ */
