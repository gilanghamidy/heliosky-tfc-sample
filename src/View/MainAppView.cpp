/*
 * MainAppView.cpp
 *
 *  Created on: Jul 14, 2016
 *      Author: Gilang
 */

#include "View/MainAppView.h"

Evas_Object* Heliosky::View::MainAppView::CreateSidebar(Evas_Object* root)
{
	sidebarMenu.Create(root);



	return sidebarMenu;
}
