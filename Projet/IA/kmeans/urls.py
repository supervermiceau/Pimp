from django.conf.urls import url

from . import views

urlpatterns = [
	url(r'^$', views.index, name='index'),
	url(r'^scatterplot$', views.scatterplot, name='scatterplot')
]