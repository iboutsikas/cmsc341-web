---
layout: default
parent: "Project 3: B is NOT for binary"
title: 'Introduction'
nav_order: 1
---
# {{page.title}}
{% assign project = site.data.project.project3 %}
{% include due_date.html project=project%}
{% if project.changelog %}
{% include changelog.html project=project %}
{% endif %}

<p>
In this project you will be implementing a B-Tree as an index for a database. A
key reason to use a B-Tree is to reduce the performance penalty of storing part
of your tree, as well as the actual data for the tree, on disc (or some other
form of dense, persistent storage).
</p>
<p>
Working with real databases or with disks (we are talking hardware here, not
just file I/O) might sound fun to some of you. But it is also a bit too much,
and outside the scope of this class. <b>To that end we will be faking most of
it, with code that will be provided</b>. You can use this code to see how your
implementation will be used. We will also have a summary of the provided code
later on.
</p>

<p>
You will have to make quite a few design choices this time as well. We will be
providing some ideas and suggestions to get you started, but it is always better
to implement something you understand, instead of following a suggestion
blindly. It is always about pros and cons!
</p>

<div class="alert alert-warning">
    We will be using boxes like this one to draw your attention to things. There
    are many colors included! If something <b>MUST</b> be implemented in a
    specific way, we will let you know with a similar box as well.
</div>

<p>
    Please take your time in reading this website, and remember that there is
    always a search bar at the top of the site, so you can search the content
    faster!
</p>