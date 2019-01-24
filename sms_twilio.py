from twilio.rest import Client

accountSID = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"   # account SID from Twilio account
authToken = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"    # authentication token from Twilio account

twilioClient = Client(accountSID, authToken)

twilioNumber = "+18081234567"   # Twilio-given phone number to send from
cellNumber = "+18082345678"     # personal phone number registered on Twilio account to send to


message = twilioClient.messages.create(
    body="hi from me", 
    from_=twilioNumber, 
    to=cellNumber)
