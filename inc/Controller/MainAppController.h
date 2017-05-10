/*
 * MainAppController.h
 *
 *  Created on: Jul 14, 2016
 *      Author: Gilang
 */

#ifndef MAINAPPCONTROLLER_H_
#define MAINAPPCONTROLLER_H_

#include "Heliosky.h"
#include "View/MainAppView.h"

#include "Controller/PostListController.h"

namespace Heliosky
{
	namespace Controller
	{
		class MainAppController : public TFC::Framework::ControllerBase
		{
		private:
			View::MainAppView mainAppView;

			// Embed PostListController here so it can be attached to SidebarView (MainAppView parent)
			Controller::PostListController postListController;
		public:
			// Controller must have constructor with this exact parameter
			MainAppController(TFC::Framework::ControllerManager* m);
			virtual ~MainAppController();


			virtual void OnLoad(TFC::ObjectClass* data);
		};
	}
}



#endif /* MAINAPPCONTROLLER_H_ */
