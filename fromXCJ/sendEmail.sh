cd /home/ubuntu/Desktop/
echo From:$1 >tsps_email.txt
echo To:$2 >>tsps_email.txt
echo Subject: $3 `date` >>tsps_email.txt
echo $4 >>tsps_email.txt

ssmtp $2 </home/ubuntu/Desktop/tsps_email.txt
