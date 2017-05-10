/*
 * PostController.h
 *
 *  Created on: May 10, 2017
 *      Author: gmh
 */

#ifndef CONTROLLER_POSTCONTROLLER_H_
#define CONTROLLER_POSTCONTROLLER_H_

#include "View/PostView.h"

using namespace Heliosky::View;

namespace Heliosky {
	namespace Controller {
		class PostController: public TFC::Framework::ControllerBase {
		private:
			// Define the view of the controller here
			PostView postView;

		public:
			// Controller must have constructor with this exact parameter
			PostController(TFC::Framework::ControllerManager* m);

			// This method will be called when the controller is loaded by the application
			virtual void OnLoad(TFC::ObjectClass* param);

			// This method will be called before leaving the controller
			virtual TFC::ObjectClass* OnUnload();
		};
	}
}




#endif /* CONTROLLER_POSTCONTROLLER_H_ */
