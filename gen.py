import os
import xml.etree.ElementTree as ET
import json
from jinja2 import Environment, FileSystemLoader

def load_template(template_name):
    template_dir = os.path.join(os.path.dirname(__file__), 'templates')
    env = Environment(loader=FileSystemLoader(template_dir))
    return env.get_template(template_name)

def scan_folder(folder_path):
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            yield os.path.join(root, file)
            
def parse_xml(file):
    tree = ET.parse(file)
    root = tree.getroot()
    
    result = []
    
    for child in root:
        if child.tag == 'testcase':
            attrs = child.attrib
            failures = []
            
            for failure in child:
                failures.append({
                    'type': failure.attrib['type'],
                    'message': failure.attrib['message'],
                })
            
            result.append({
                'group': attrs['classname'],
                'name': attrs['name'],
                'time': attrs['time'],
                'status': 'success' if len(failures) == 0 else 'failure',
                'failures': failures,
                'assertions': attrs['assertions'],
                'file': attrs['file'],
                'line': attrs['line'],
            })
    
    return result
            
parsed_data = []
for file in scan_folder('xml/'):
    # Parse XML files
    if file.endswith('.xml'):
        data = parse_xml(file)
        fail = len([x for x in data if x['status'] == 'failure'])
        
        parsed_data.append({
            'file': file.split('/')[-1],
            'failures': fail,
            'total': len(data),
            'data': data,
        })
        
print(json.dumps(parsed_data, indent=4))
        
# Generate HTML report
template = load_template('template.html')

output_html = template.render(reports=parsed_data)
output_file = 'target.html'

with open(output_file, 'w') as f:
    f.write(output_html)
        
    
        