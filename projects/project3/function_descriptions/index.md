---
layout: default
parent: "Project 3: B is NOT for binary"
title: "Function Descriptions"
nav_order: 4
nav_exclude: false
search_exclude: false
has_children: true
---
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}