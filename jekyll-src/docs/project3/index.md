---
layout: default
title: "Project 3: B is NOT for binary"
nav_order: 2
nav_exclude: false
search_exclude: false
has_children: true
---

# {{page.title}}
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

<p>
Please take your time in reading this website, and remember that there is always
a search bar at the top of the site, so you can search the content faster!
</p>