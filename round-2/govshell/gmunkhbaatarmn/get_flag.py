#! /usr/local/bin/python
import requests

def hack_the_server(){
	r = requests.post('http://backend.government.local', data={'username': 'dorj', 'password': 'aaabbbccc'});
	print 'status_code', r.status_code
	print 'response_body', r.text
}
