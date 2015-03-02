from twilio.rest import TwilioRestClient 

text = open('address.txt','r')
address = text.readline()

#Get personal ACCOUNT_SID and AUTH_TOKEN at https://www.twilio.com/try-twilio
ACCOUNT_SID = "" 
AUTH_TOKEN = "" 
 
client = TwilioRestClient(ACCOUNT_SID, AUTH_TOKEN) 
 
#Insert "to" number as your personal number and from as your twilio number
client.messages.create(
	to="", 
	from_="+", 
	body="Your RPi IP addr:" + address,  
)
