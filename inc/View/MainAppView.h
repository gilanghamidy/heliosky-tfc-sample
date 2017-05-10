/*
 * MainAppView.h
 *
 *  Created on: Jul 14, 2016
 *      Author: Gilang
 */

#ifndef MAINAPPVIEW_H_
#define MAINAPPVIEW_H_

#include "Heliosky.h"
#include "TFC/Components/SidebarView.h"
#include "TFC/Components/TreeMenu.h"

namespace Heliosky
{
	namespace View
	{

		class MainAppView : public TFC::Components::SidebarView
		{
		private:
			TFC::Components::TreeMenu sidebarMenu;
		protected:
			virtual Evas_Object* CreateSidebar(Evas_Object* root);
		};

	}
}



#endif /* MAINAPPVIEW_H_ */
