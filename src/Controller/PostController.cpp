/*
 * PostController.cpp
 *
 *  Created on: May 10, 2017
 *      Author: gmh
 */

#include "Heliosky.h"
#include "Controller/PostController.h"

Heliosky::Controller::PostController::PostController(TFC::Framework::ControllerManager* m) :
	ControllerBase(m, &postView, CONTROLLER_POST)
{
}

void Heliosky::Controller::PostController::OnLoad(TFC::ObjectClass* param)
{
}

TFC::ObjectClass* Heliosky::Controller::PostController::OnUnload()
{
}
