/*
 * PostView.cpp
 *
 *  Created on: May 10, 2017
 *      Author: gmh
 */

#include "View/PostView.h"

Evas_Object* Heliosky::View::PostView::CreateView(Evas_Object* root)
{
	this->layout = elm_layout_add(root);

	std::string path = TFC::Framework::ApplicationBase::GetResourcePath("edc/Post.edj");

	elm_layout_file_set(this->layout, path.c_str(), "main");
	evas_object_size_hint_weight_set(this->layout, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	evas_object_size_hint_align_set(this->layout, EVAS_HINT_FILL, EVAS_HINT_FILL);
	evas_object_show(this->layout);

	return this->layout;
}

Heliosky::View::PostView::PostView()
{

}

void Heliosky::View::PostView::SetModel(const Heliosky::Model::Post& model)
{

}
