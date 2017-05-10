/*
 * MainAppController.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Gilang
 */

#include "Controller/MainAppController.h"

Heliosky::Controller::MainAppController::MainAppController(TFC::Framework::ControllerManager* m) :
	TFC::Framework::ControllerBase(m, &mainAppView, CONTROLLER_MAINAPP),
	postListController(m)
{
}

Heliosky::Controller::MainAppController::~MainAppController() {
}

void Heliosky::Controller::MainAppController::OnLoad(TFC::ObjectClass* data)
{
	// Attach the PostListController view to SidebarView container
	mainAppView.Attach(postListController.View);

	// Propagate the loading of PostListController
	postListController.Load(nullptr);
}
