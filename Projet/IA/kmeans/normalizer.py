#from ai.normalize import Normalize
#from string import string
#from sets import set

import csv
import copy
#from collections import OrderedDict

class Normalizer():
	def load_csv(self, dataFile, columns):
		# print("Load CSV from "+dataFile)
		self.columns = list(columns)
		self.data = []
		print('colonne selectionné')
		print(self.columns)

		d = open(dataFile,'r')
		reader = csv.reader(d)
		for row in reader:
			r=[]
			for i in self.columns:
				r.append(float(row[i]))
			self.data.append(r)
		# d.close()
		return self.normalize()
	
	def normalize(self):
		for i in range(len(self.data[0])):
			column=[]
			for row in self.data:
				column.append(row[i])
			mx = max(column)
			mn = min(column)
			for row in self.data:
				if mn!=mx:
					row[i] = ((row[i]-mn)/(mx-mn))
				else:
					row[i] = 0
		return self.data
