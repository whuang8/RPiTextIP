from twilio.rest import TwilioRestClient 

text = open('address.txt','r')
address = text.readline()

ACCOUNT_SID = "AC649285e6c28e16f014f1da368c53967a" 
AUTH_TOKEN = "60d28108598d7bb0b868e8d34e3bc58b" 
 
client = TwilioRestClient(ACCOUNT_SID, AUTH_TOKEN) 
 
client.messages.create(
	to="9738689358", 
	from_="+18622363859", 
	body="Your RPi IP addr:" + address,  
)
