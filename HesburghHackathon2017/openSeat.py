#!/usr/bin/python

from kivy.app import App
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label
from kivy.uix.button import Button

import json
import requests
import os

Fish = 'Welcome to openSeat\n\nSelect the room you want to check seats for.'
def ChangeDLS(begin, end):
	global Fish
	os.system("./getVals.py %s %s" %(begin, end))
	with open('results.txt', 'r') as myfile:
		DA = myfile.readline()
		DT = myfile.readline()
		CA = myfile.readline()
		CT = myfile.readline()
		TA = myfile.readline()
		TT = myfile.readline()


	Fish = "~Center for Digital Scholorship~\n\nDesks Available:              "+DA+"\nDesks Taken:                   "+DT+"\n\nComputers Available:     "+CA+"\nComputers Taken:        "+CT+"\n\nTables Available:            "+TA+"\nTables Taken:                 "+TT
def ChangeComingSoon():
	global Fish
	Fish = 'Coming Soon\n'
def Change12(begin, end):
	global Fish
	os.system("./getVals.py %s %s" %(begin, end))
	with open('results.txt', 'r') as myfile:
		DA = myfile.readline()
		DT = myfile.readline()
		CA = myfile.readline()
		CT = myfile.readline()
		TA = myfile.readline()
		TT = myfile.readline()


	Fish = "~12th Floor~\n\nDesks Available:            "+DA+"\nDesks Taken:                 "+DT+"\n\nComputers Available:      "+CA+"\nComputers Taken:           "+CT+"\n\nTables Available:             "+TA+"\nTables Taken:                  "+TT




class openSeatApp(App):
	def build(self):
		MainLayout = BoxLayout(orientation='horizontal')
		LeftLayout = BoxLayout(orientation='vertical')
		twelve = Button(text="12th Floor", on_press = self.update12)
		eleven = Button(text="11th Floor", on_press = self.updateComingSoon)
		ten = Button(text="10th Floor", on_press = self.updateComingSoon)
		nine = Button(text = "9th Floor", on_press = self.updateComingSoon)
		eight = Button(text = "8th Floor", on_press = self.updateComingSoon)
		seven = Button(text = "7th Floor", on_press = self.updateComingSoon)
		six = Button(text = "6th Floor", on_press = self.updateComingSoon)
		five = Button(text = "5th Floor", on_press = self.updateComingSoon)
		four = Button(text = "4th Floor", on_press = self.updateComingSoon)
		three = Button(text = "3rd Floor", on_press = self.updateComingSoon)
		two = Button(text = "2nd Floor", on_press = self.updateComingSoon)
		DLS = Button(text = "Center for Digital Scholorship", on_press = self.updateDLS)
		NFBowl = Button(text = "North Fishbowl", on_press = self.updateComingSoon)
		SFBowl = Button(text = "South Fishbowl", on_press = self.updateComingSoon)
		LeftLayout.add_widget(twelve)
		LeftLayout.add_widget(eleven)
		LeftLayout.add_widget(ten)
		LeftLayout.add_widget(nine)
		LeftLayout.add_widget(eight)
		LeftLayout.add_widget(seven)
		LeftLayout.add_widget(six)
		LeftLayout.add_widget(five)
		LeftLayout.add_widget(four)
		LeftLayout.add_widget(three)
		LeftLayout.add_widget(two)
		LeftLayout.add_widget(DLS)
		LeftLayout.add_widget(NFBowl)
		LeftLayout.add_widget(SFBowl)
		Fishbowl = Label(text=Fish)
		MainLayout.add_widget(LeftLayout)
		MainLayout.add_widget(Fishbowl)
		return MainLayout
	def updateDLS(self,event):
		ChangeDLS(251, 291)
		App.get_running_app().stop()
	def updateComingSoon(self,event):
		ChangeComingSoon()
		App.get_running_app().stop()
	def update12(self,event):
		Change12(200, 251)
		App.get_running_app().stop()

if __name__ == '__main__':
	while(True):
		openSeatApp().run()
