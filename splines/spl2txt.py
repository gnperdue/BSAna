#!/usr/bin/env python

# This script reads in a GENIE xml spline file, assuming one channel
# and neutrino and antineutrino entries (muon type) and parses them
# into two text files for easier plotting with Python / R.

import sys
from xml.etree import ElementTree as ET


def get_txtname(alg_name, flavor, xml_name):
    base_name = xml_name.split(".")[0]
    return alg_name + flavor + base_name + '.txt'


def decode_flavor(flavor):
    """
    Change the PDG code into a string.
    """
    return {
        '-16': 'tau_antineutrino',
        '-14': 'muon_antineutrino',
        '-12': 'electron_antineutrino',
        '12': 'electron_neutrino',
        '14': 'muon_neutrino',
        '16': 'tau_neutrino'
    }.get(flavor, 'unknown')


def get_neutrino_description(description):
    """
    Take a GENIE description string like:
        'genie::ReinSeghalCOHPiPXSec/Default/nu:-14;tgt:1000060120;
         proc:Weak[CC],COH;hmult:(p=0,n=0,pi+=0,pi-=1,pi0=0);'
    and return:
        ReinSeghalCOHPiPXSec, -14
    Also available:
        tgt = components[1].split(':')[1]
        proc = components[2].split(':')[1]
        hadrons = components[3].split(':')[1]
    """
    components = description.split(';')
    alg_flavor = components[0].split('/')
    alg = alg_flavor[0].split(':')[-1]
    flavor = alg_flavor[-1].split(':')[-1]
    return alg, decode_flavor(flavor)


def process_spline(spline):
    knots = spline.findall('./knot')
    xsecs = []
    for knot in knots:
        e = knot.find('./E')
        x = knot.find('./xsec')
        xsecs.append((e.text, x.text))
    alg, flavor = get_neutrino_description(spline.get('name'))
    spline_dict = {'Algorithm': alg, 'Flavor': flavor, 'Xsecs': xsecs}
    return spline_dict


def make_file(xsec_dict, xml_name):
    flavor = xsec_dict['Flavor']
    helicity = flavor.split('_')[1]
    filename = get_txtname(xsec_dict['Algorithm'], flavor, xml_name)
    with open(filename, 'w') as f:
        f.write('#%s\n' % helicity)
        f.write('Energy CrossSection\n')
        e_xs_pairs = xsec_dict['Xsecs']
        for p in e_xs_pairs:
            f.write('%s %s\n' % (p[0], p[1]))


def transform(xml_file_name):
    """
    Splitting structure generally assumes a GENIE xml file circa 2.8.
    """
    xsec_xml = ET.parse(xml_file_name)
    splines = xsec_xml.findall('./spline')
    neutrino_xsecs = []

    for spline in splines:
        xsec_dict = process_spline(spline)
        neutrino_xsecs.append(xsec_dict)

    for xsec in neutrino_xsecs:
        make_file(xsec, xml_file_name)


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print "This script requires a filename argument."
        sys.exit(2)

    transform(sys.argv[1])
