from django.shortcuts import render
from django.http import HttpResponse
from .kmeanclusterer import KMeanClusterer

def index(request):
	context = {
		'columns': [
			[0, 'wf_make',True],
			[1, 'wf_address',True],
			[2, 'wf_all',False],
			[4, 'wf_our',True],
			[3, 'wf_3d',True],
			[5, 'wf_over',False],
			[6, 'wf_remove',False],
			[7, 'wf_internet',False],
			[8, 'wf_order',True],
			[9, 'wf_mail',True],
			[10, 'wf_receive',False],
			[11, 'wf_will',False],
			[12, 'wf_people',False],
			[13, 'wf_report',True],
			[14, 'wf_addresses',False],
			[15, 'wf_free',False],
			[16, 'wf_business',False],
			[17, 'wf_email',False],
			[18, 'wf_you',False],
			[19, 'wf_credit',False],
			[20, 'wf_your',False],
			[21, 'wf_font',False],
			[22, 'wf_000',False],
			[23, 'wf_money',False],
			[24, 'wf_hp',False],
			[25, 'wf_hpl',False],
			[26, 'wf_george',False],
			[27, 'wf_650',False],
			[28, 'wf_lab',False],
			[29, 'wf_labs',False],
			[30, 'wf_telnet',False],
			[31, 'wf_857',False],
			[32, 'wf_data',False],
			[33, 'wf_415',False],
			[34, 'wf_85',False],
			[35, 'wf_technology',False],
			[36, 'wf_1999',False],
			[37, 'wf_parts',False],
			[38, 'wf_pm',False],
			[39, 'wf_direct',False],
			[40, 'wf_cs',False],
			[41, 'wf_meeting',False],
			[42, 'wf_original',False],
			[43, 'wf_project',False],
			[44, 'wf_re',False],
			[45, 'wf_edu',True],
			[46, 'wf_table',True],
			[47, 'wf_conference',False],
			[48, 'cf_;',False],
			[49, 'cf_(',False],
			[50, 'cf_[',False],
			[51, 'cf_!',False],
			[52, 'cf_$',False],
			[53, 'cf_#',True],
			[54, 'crl_average',False],
			[55, 'crl_longest',True],
			[56, 'crl_total',True],
			[57, 'spam',True],
			
		]

	}
	return render(request, 'kmeans/index.html', context)

def scatterplot(request):
	columns = request.POST.getlist('columns[]')
	columns = map(int,columns)
	c = KMeanClusterer(int(request.POST['k']),int(request.POST['n']),int(request.POST['p']),'./kmeans/data',columns)
	return render(request, 'kmeans/scatterplot.html', { 'data': c.returnTable()})
