# Credential-Harvesting

This program makes use of the Windows API to access credentials stored in the Windows Credential Manager. The credentials are then retrieved and written to a text file.

## Use cases

Red team engagement compromising an enterprise would gain initial access and then escalate privellages, mimicking real attackers. They would then make a report on their findings and inform management on the current infrastructure in the organization.

---
Auditing of stored credentials on windows systems. Security professionals can then use it for checking whether the credentials are stored securely, and help the organization enforce security best practises.

>[!Warning]
> This repository contains penetration testing tools developed in C++. These tools are intended strictly for educational and ethical hacking purposes. They should only be used in environments where you have explicit permission to test. I am not responsible for any misuse, damage, or legal issues arising from the use of this program. It is the responsibility of the user to comply with all applicable laws and regulations.
