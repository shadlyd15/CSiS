import time
import base64
import socket

def mail_client(recipient, subject, message, sender = "shadly.salahuddin@uni-wuppertal.de", smtp_host = "mail.uni-wuppertal.de", smtp_port = 25):
  ret_val = False
  smtp_host_port = (smtp_host, smtp_port)
  smtp_client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
  smtp_client_socket.connect(smtp_host_port)
  
  # 220 	<domain> Service ready
  if '220' in smtp_client_socket.recv(1024).decode():
    print("SMTP Connected")
    smtp_client_socket.send('HELO SMTP\r\n'.encode())
    
    # 250 	Requested mail action okay, completed
    if '250' in smtp_client_socket.recv(1024).decode():
      print("HELO Exchanged")

      smtp_client_socket.send("AUTH PLAIN ".encode() + base64.b64encode(("\x00"+username+"\x00"+password).encode()) + "\r\n".encode())
      if not "unsuccessful" in smtp_client_socket.recv(1024).decode():
        print("Username Authenticated")
        email_sender = "MAIL FROM:<" + sender + ">\r\n"
        smtp_client_socket.send(email_sender.encode())
        
        # 250 	Requested mail action okay, completed
        if '250' in smtp_client_socket.recv(1024).decode():
          print("Sender Set")
          email_recipient = "RCPT TO:<" + recipient + ">\r\n"
          smtp_client_socket.send(email_recipient.encode())

          # 250 	Requested mail action okay, completed
          if '250' in smtp_client_socket.recv(1024).decode():
            print("Recipient Set")
            data = "DATA\r\n"
            smtp_client_socket.send(data.encode())

            # 354 	Start mail input; end with <CRLF>.<CRLF>
            if '354' in smtp_client_socket.recv(1024).decode(): 
              print("DATA Set")
              email_subject = "Subject: " + subject + "\r\n\r\n"
              smtp_client_socket.send(email_subject.encode())

              date = time.strftime("%a, %d %b %Y %H:%M:%S +0000", time.gmtime()) + "\r\n\r\n"
              smtp_client_socket.send(date.encode())
              smtp_client_socket.send("\r\n".encode())
              smtp_client_socket.send(message.encode())
              smtp_client_socket.send("\r\n.\r\n".encode())

              # 250 	Requested mail action okay, completed
              if '250' in smtp_client_socket.recv(1024).decode():
                print("Email Queued")
                quit = "QUIT\r\n"
                smtp_client_socket.send(quit.encode())

                # 221 	<domain> Service closing transmission channel
                if '221' in smtp_client_socket.recv(1024).decode():
                  print("Service closing transmission channel")
                  smtp_client_socket.close()
                  ret_val = True
  return ret_val


username = "1943290"
password = "************"
filename = "email_content.txt"
recipient_email = input("Please Enter Recipient Email : ") # Input Format : "<Email Address>"

file = open(filename, "r")

if mail_client(recipient_email, "Test", file.read()):
  print("Email Sent Successfully")
else:
  print("Error : Email Not Sent")

