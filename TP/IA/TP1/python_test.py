import unittest

class Test(unittest.TestCase):
	
	def setUp(self):
		pass
		
	def tearDown(self):
		pass
		
	def testHelloTest(self):
		a = 1
		b = 1
		self.assertTrue(a == b, "a is b")
		
if __name__== "__main__":
	#import sys:sys.argv = ['', 'Test.testHelloTest']
	unittest.main()
