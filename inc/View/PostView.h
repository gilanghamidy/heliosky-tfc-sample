/*
 * PostView.h
 *
 *  Created on: May 10, 2017
 *      Author: gmh
 */

#ifndef VIEW_POSTVIEW_H_
#define VIEW_POSTVIEW_H_

#include "TFC/Components/GenericList.h"
#include "TFC/Framework/Application.h"
#include "Model/Post.h"

namespace Heliosky
{
	namespace View
	{
		class PostView : public TFC::Framework::ViewBase
		{
		private:
			// Create GenericList component
			TFC::Components::GenericList postList;
			Heliosky::Model::Post const* model { nullptr };

			Evas_Object* layout { nullptr };
		protected:
			virtual Evas_Object* CreateView(Evas_Object* root);

		public:
			PostView();

			void SetModel(Heliosky::Model::Post const& model);
		};
	}

}



#endif /* VIEW_POSTVIEW_H_ */
