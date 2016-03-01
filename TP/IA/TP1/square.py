class Square(object):
	'''
	classdocs
	'''
	def setSize(self, size):
		self.size = size
			
	def getSurface(self):
		return self.size * self.size
				
	def __init__(self):
		'''	
			constructor
		'''
		print("Square constructor")
