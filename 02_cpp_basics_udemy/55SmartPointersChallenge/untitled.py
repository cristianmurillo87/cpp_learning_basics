import random
from datetime import date, datetime

class MyClass(object):
	def __init__(self, arg1, arg2):
		self.arg1 = arg1
		self.arg2 = arg2

	@classmethod
	def _myclass(cls, arg1, arg2):
		return cls(arg1, arg2)

	def getarg1():
		return arg1

	def getarg2():
		return arg2

	