#
# Example of an execution of this program:
# 
#  svn info -R | python svnstats.py > stats_by_user
#

import sys
import csv
import pprint 

from mapreduce import map_reduce

def main():
  fields = ["Path", "Name", "URL", "Revision", "Last Changed Author",
            "Last Changed Rev", "Last Changed Date", "Text Last Updated"]

  data = []

  tmpval = {}
  isdir = False

  for line in sys.stdin:
    field = line.split(': ')
    key = field[0]
    value = ''.join(field[1:]).strip()

    if key in fields:
      tmpval[key] = value
    
    if key == "Node Kind" and value == "directory":
      isdir = True
    
    if len(line) == 1:
      if not isdir:
        data.append(tmpval)
      
      
      tmpval = {}
      isdir = False

  #csvWriter = csv.DictWriter(sys.stdout, fields, quoting=csv.QUOTE_ALL)
  #csvWriter.writerow(dict(zip(fields, fields)))
  #csvWriter.writerows(data)

  users2problemid = map_reduce(data, lambda x: (x['Last Changed Author'], x['Path']))
  pprint.pprint(users2problemid)
  
if __name__ == '__main__':
  main()
  
  #import doctest
  #print(doctest.testmod())
