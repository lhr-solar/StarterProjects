#!/bin/bash -ex

# Save user to variable
read -p "Username: " username

# This will give you write access to the file where priority limits are stored
sudo chmod +w /etc/security/limits.conf

# Create a group called realtime to give the permission to
sudo groupadd realtime

# Add the current user to the newly created group
sudo usermod -a -G realtime $username

# Check if this line is already in the file. If it is not, add it.
# This will give the user group @realtime an unlimited realtime priority limit, allowing the simulator to run.
sudo grep -qxF '@realtime - rtprio unlimited' /etc/security/limits.conf || sudo echo '@realtime - rtprio unlimited' >> /etc/security/limits.conf
#-q be quiet
#-x match the whole line
#-F pattern is a plain string

curl ascii.live/rick

echo -e "\nFinished!\n"
