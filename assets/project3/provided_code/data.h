#pragma once

#include <vector>

#include "person.h"
#include "distributed_index.h"

std::vector<Person> Employees = {
    {  46, "Simone",    "Rocha" },
    { 168, "Abiha",     "Clay" },
    {  90, "Mikolaj",   "Woodcock" },
    { 242, "Nannie",    "Higgins" },
    {  18, "Zach",      "Cortez" },
    {  11, "Esmai",     "Blundell" },
    { 125, "Kathleen",  "Markham" },
    { 250, "Solomon",   "Todd" },
    {  92, "Hadi",      "Busby" },
    { 154, "Ihsan",     "Medina" },
    {  12, "Nellie",    "Driscoll" },
    { 192, "Matt",      "Forbes" },
    { 117, "Henri",     "Guevara" },
    { 155, "Willow",    "Griffin" },
    { 137, "Malikah",   "Crawford" },
    { 181, "Ralphie",   "Riddle" },
    {  61, "Hussein",   "Rodriguez" },
    {  39, "Fahad",     "Guzman" },
    { 108, "Jevon",     "Love" },
    {  52, "Abel",      "Gunn" }
};

std::vector<Person> Employees_Ascending = {
    {  11, "Esmai",     "Blundell" },
    {  12, "Nellie",    "Driscoll" },
    {  18, "Zach",      "Cortez" },
    {  39, "Fahad",     "Guzman" },
    {  46, "Simone",    "Rocha" },
    {  52, "Abel",      "Gunn" },
    {  61, "Hussein",   "Rodriguez" },
    {  90, "Mikolaj",   "Woodcock" },
    {  92, "Hadi",      "Busby" },
    { 108, "Jevon",     "Love" },
    { 117, "Henri",     "Guevara" },
    { 125, "Kathleen",  "Markham" },
    { 137, "Malikah",   "Crawford" },
    { 154, "Ihsan",     "Medina" },
    { 155, "Willow",    "Griffin" },
    { 168, "Abiha",     "Clay" },
    { 181, "Ralphie",   "Riddle" },
    { 192, "Matt",      "Forbes" },
    { 242, "Nannie",    "Higgins" },
    { 250, "Solomon",   "Todd" },
};

std::vector<Person> Employees_Descending = {
    { 250, "Solomon",   "Todd" },
    { 242, "Nannie",    "Higgins" },
    { 192, "Matt",      "Forbes" },
    { 181, "Ralphie",   "Riddle" },
    { 168, "Abiha",     "Clay" },
    { 155, "Willow",    "Griffin" },
    { 154, "Ihsan",     "Medina" },
    { 137, "Malikah",   "Crawford" },
    { 125, "Kathleen",  "Markham" },
    { 117, "Henri",     "Guevara" },
    { 108, "Jevon",     "Love" },
    {  92, "Hadi",      "Busby" },
    {  90, "Mikolaj",   "Woodcock" },
    {  61, "Hussein",   "Rodriguez" },
    {  52, "Abel",      "Gunn" },
    {  46, "Simone",    "Rocha" },
    {  39, "Fahad",     "Guzman" },
    {  18, "Zach",      "Cortez" },
    {  12, "Nellie",    "Driscoll" },
    {  11, "Esmai",     "Blundell" },
};

std::vector<DistributedIndex> DistributedIndices = {
    { 0xDEADBEEF, "166.191.71.192",     133 },
    { 0x8BADF00D, "124.151.35.65",      23 },
    { 0xB105F00D, "63.185.33.6",        214 },
    { 0xBAAAAAAD, "73.239.227.237",     21 },
    { 0xFACEFEED, "14.40.190.87",       174 },
    { 0xFEEDC0DE, "69.195.149.47",      136 },
    { 0xDEADC0DE, "17.155.249.223",     206 },
    { 0xBADDCAFE, "227.153.96.203",     135 },
    { 0xAFFEC7ED, "150.10.135.43",      6 },
    { 0xF1A7F007, "89.153.27.69",       140 }
};