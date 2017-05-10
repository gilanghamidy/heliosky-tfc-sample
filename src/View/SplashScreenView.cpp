/*
 * SplashScreenView.cpp
 *
 *  Created on: Apr 11, 2016
 *      Author: Gilang M. Hamidy (g.hamidy@samsung.com)
 */

#include "View/SplashScreenView.h"


Heliosky::View::SplashScreenView::SplashScreenView() :
	rootLayout(nullptr)
{
}

Heliosky::View::SplashScreenView::~SplashScreenView()
{
}

Evas_Object* Heliosky::View::SplashScreenView::CreateView(Evas_Object* root)
{
	std::string path = TFC::Framework::ApplicationBase::GetResourcePath("edc/SplashScreen.edj");

	this->rootLayout = elm_layout_add(root);
	elm_layout_file_set(this->rootLayout, path.c_str(), "main");
	evas_object_size_hint_weight_set(this->rootLayout, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(this->rootLayout, EVAS_HINT_FILL, EVAS_HINT_FILL);

	evas_object_show(this->rootLayout);

	// Return primitive Elementary container to be attached to the view
	return rootLayout;
}

Evas_Object* Heliosky::View::SplashScreenView::GetTitleLeftButton(char const** buttonPart)
{
	return nullptr;
}

Evas_Object* Heliosky::View::SplashScreenView::GetTitleRightButton(char const** buttonPart)
{
	return nullptr;
}

char const* Heliosky::View::SplashScreenView::GetContentStyle()
{
	return "tabbar/icon/notitle";
}
