from twilio.rest import Client

accountSID = "AC828fc43d5f7280f5faa4614036db9c92"
authToken = "533763d2ce73c88277bd074945aa61f9"

twilioClient = Client(accountSID, authToken)

twilioNumber = "+18088244319"
cellNumber = "+18086870054"


message = twilioClient.messages.create(
    body="hi from me", 
    from_=twilioNumber, 
    to=cellNumber)