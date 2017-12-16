import sys
import json

print sys.argv[1]
print sys.argv[1][1]

# for elements in sys.argv:
#     # print("ini for")
#     d = json.loads(sys.argv)
#     # print elements
#     print d['name']['pi']
#     # print("fin for")

# print("fin python")
try:
    js = json.loads(sys.argv[1])

    # pretty printing of json-formatted string
    print json.dumps(js, sort_keys=True, indent=4)

    print "JSON parsing example: ", js['name']
    print "JSON parsing example: ", js['game']
    print "JSON parsing example: ", js['velocity']
    print "Complex JSON parsing example: ", js['object']['value']

except (ValueError, KeyError, TypeError):
    print "JSON format error"
