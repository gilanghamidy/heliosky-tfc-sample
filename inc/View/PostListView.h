/*
 * PostListView.h
 *
 *  Created on: Jul 14, 2016
 *      Author: Gilang
 */

#ifndef POSTLISTVIEW_H_
#define POSTLISTVIEW_H_

#include "Heliosky.h"
#include "TFC/Components/GenericList.h"
#include "Model/Post.h"

namespace Heliosky
{
	namespace View
	{
		class PostListView : public TFC::Framework::ViewBase
		{
		private:
			// Create GenericList component
			TFC::Components::GenericList postList;
		protected:
			virtual Evas_Object* CreateView(Evas_Object* root);

		public:
			PostListView();

			// Declare redirection of GenericList's members so it can be exposed
			// to the consumer of PostListView.

			// decltype is C++ keyword to infer the type from an expression
			// Definition below means that creating a reference to postList.DataSource member
			// postList.DataSource itself is a mutable property
			decltype(postList.DataSource)& PostListDataSource;
			decltype(postList.eventItemClicked)& eventListItemClicked;

			class PostListItemClassDef : public TFC::Components::SimpleGenericListItemClass<Model::Post>
			{
			public:
				PostListItemClassDef();
				virtual Evas_Object* GetContent(Model::Post* data, Evas_Object *obj, const char *part);
			} static PostListItemClass;
		};
	}

}



#endif /* POSTLISTVIEW_H_ */
