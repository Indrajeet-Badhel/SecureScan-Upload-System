# SecureScan-Upload-System

**SecureScan Upload System** ensures safe file uploads by scanning them in real time with ClamAV and emailing instant reports. Built with PHP, JavaScript, Python, and C, it detects threats, flags malicious files, and keeps users informed—enhancing trust and security.

The SecureScan Upload System is a secure file upload platform that scans user-uploaded files in real-time using the **ClamAV** antivirus engine. It provides automated email reports detailing the scan results, ensuring user awareness and protection against cyber threats such as malware, ransomware, and phishing.

This system integrates frontend simplicity with backend robustness, creating a scalable and secure file handling environment for modern web applications.

---

## TECHNOLOGIES USED

**Frontend:**
- HTML  
- CSS  
- JavaScript

**Backend:**
- PHP (Handles file upload and server-side logic)  
- Python (Handles email automation using SMTP)  
- C (Interfaces with ClamAV for scanning)

**Security:**
- ClamAV (Open-source antivirus for real-time scanning)

**Operating System:**
- Linux-based system (Tested on Ubuntu via WSL)

**Development Environment:**
- Windows Subsystem for Linux (WSL)  
- Apache 2.4 (via XAMPP or manual installation)

---

## KEY FEATURES

### REAL-TIME FILE SCANNING
Every uploaded file is scanned immediately using ClamAV to ensure it is free of viruses or malware.

### AUTOMATED EMAIL NOTIFICATIONS
After scanning, users receive a detailed email report with the scan results using Python's SMTP library.

### MALICIOUS FILE FLAGGING
Suspicious or infected files are flagged and can be optionally removed or quarantined.

### USER-FRIENDLY INTERFACE
The web interface is intuitive and allows easy file uploads with immediate feedback.

### MODULAR STRUCTURE
Frontend, backend, and scanning logic are separated into different modules for easier maintenance and scalability.

---

