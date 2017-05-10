/*
 * SplashScreenView.h
 *
 *  Created on: Apr 11, 2016
 *      Author: Gilang M. Hamidy (g.hamidy@samsung.com)
 */

#ifndef SPLASHSCREENVIEW_H_
#define SPLASHSCREENVIEW_H_

#include "Heliosky.h"

#include "TFC/Components/Field.h"

namespace Heliosky {
	namespace View {
		class SplashScreenView:
				public TFC::Framework::ViewBase, 			// Every view has to inherit ViewBase
				public TFC::Framework::INaviframeContent	// Interface INaviframeContent. See below for description
		{
		private:
			// Declare members here to hold view data, such as pointer to Elementary objects
			Evas_Object* rootLayout;

		protected:
			// Every view has to override CreateView method to return the components to its parent
			virtual Evas_Object* CreateView(Evas_Object* root);

		public:
			SplashScreenView();
			virtual ~SplashScreenView();

			// This is the implementation of INaviframeContent, whioh describes additional rules for
			// this view when this view is attached to a naviframe object
			virtual Evas_Object* GetTitleLeftButton(char const** buttonPart);
			virtual Evas_Object* GetTitleRightButton(char const** buttonPart);
			virtual char const* GetContentStyle();

		};
	}
}



#endif /* SPLASHSCREENVIEW_H_ */
