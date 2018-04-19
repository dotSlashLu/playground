#encoding=utf8

import os
import jenkinsapi
from jenkinsapi.jenkins import Jenkins
from itertools import islice

import xml.etree.ElementTree as ET

scm_type = {
    'git': 0,
    'subversion': 0,
    'unknown': 0
}
branches = {'NONE': 0}

def set_branch(name):
    if branches.get(branch):
        branches[branch] += 1
    else:
        branches[branch] = 1


URL = None
J = Jenkins()
jobs = J.get_jobs()
for job in jobs:
    name, job_obj = job
    print name
    conf_xml = job_obj.get_config().encode('utf-8')
    root = ET.fromstring(conf_xml)
    branch_el = root.find('scm/branches/hudson.plugins.git.BranchSpec/name')
    if branch_el is None:
        # subversion?
        scm_url_el = root.find(
            'scm/locations/hudson.scm.SubversionSCM_-ModuleLocation/remote'
        )
        if scm_url_el is None:
            branches['NONE'] += 1
            scm_type['unknown'] += 1
            print 'branch is none'
            continue
        scm_url = scm_url_el.text
        branch = scm_url.split('/')[-1]
        set_branch(branch)
        scm_type['subversion'] += 1
        continue

    branch = branch_el.text
    print branch
    set_branch(branch)
    scm_type['git'] += 1

print scm_type
print branches


