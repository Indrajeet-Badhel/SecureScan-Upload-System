import smtplib
import sys
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

def send_report(to_email, report_path):
    from_email = ""
    password = ""

    # Load the scan report
    with open(report_path, "r") as file:
        report = file.read()

    msg = MIMEMultipart()
    msg["From"] = from_email
    msg["To"] = to_email
    msg["Subject"] = "Scan Report"

    msg.attach(MIMEText(report, "plain"))

    try:
        server = smtplib.SMTP("smtp.gmail.com", 587)
        server.starttls()
        server.login(from_email, password)
        server.sendmail(from_email, to_email, msg.as_string())
        server.quit()
        print("Email sent successfully.")
    except Exception as e:
        print("Error sending email:", e)

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python3 send_email.py <email> <report_path>")
    else:
        send_report(sys.argv[1], sys.argv[2])
