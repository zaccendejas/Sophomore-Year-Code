#!/usr/bin/python

import json
import grequests
import sys
begin = int(sys.argv[1])
end = int(sys.argv[2])


results = {'desk': 0, 'deskT': 0, 'computer': 0, 'computerT': 0,'table': 0, 'tableT': 0}
urls = ["https://dweet.io/get/latest/dweet/for/openSeat%s" % "%.3d" %i for i in xrange(begin, end)]
requests = (grequests.get(u) for u in urls)
responses = grequests.map(requests)
for r in responses:
    jsondata = r.json()
    wanted = jsondata['with']
    j = wanted[0].values()[0]
    if 'desk' in j and 'open' in j.values()[0]:
        results['desk']+=1
    elif 'table' in j and 'open' in j.values()[0]:
        results['table']+=1
    elif 'computer' in j and 'open' in j.values()[0]:
        results['computer']+=1
    elif 'desk' in j and 'taken' in j.values()[0]:
        results['deskT']+=1
    elif 'table' in j and 'taken' in j.values()[0]:
        results['tableT']+=1
    elif 'computer' in j and 'taken' in j.values()[0]:
        results['computerT']+=1

f = open('results.txt', 'w')

f.write(str(results['desk'])+'\n')
f.write(str(results['deskT'])+'\n')
f.write(str(results['computer'])+'\n')
f.write(str(results['computerT'])+'\n')
f.write(str(results['table'])+'\n')
f.write(str(results['tableT'])+'\n')

f.close()
