Contributors: knoxweb
Tags: meetup, meetup post by wordpress, meetup api, wordpress event
License: GPLv2 or later
License URI: http://www.gnu.org/licenses/gpl-2.0.html
 
 
== Description ==
This plugin will auto post Events to a Meetup.com Group on behalf of a Meetup.com organizer which is specified in Meetup Settings.

The Events Calendar by Modern Tribe is required for use this plugin, but it could be modified to be used with other post types instead.

You can decide if the event you are creating or editing needs to be plubished to Meetup.com or not while creating the Event in wp-admin.

You can give additional information which is only display only for the Meetup event description, and this will add a URL to the bottom of your Meetup description that leads back to the Event at your site (such as for RSVP events that do not use Meetup RSVP options).

In Meetup Settings you can add one Meetup.com user's User API Key, a single Group ID for a valid Meetup.com Group that user has permissions to post new Meetup events to, and one Venue ID that can be found in Group Settings on Meetup.com.

All users who can post Events will then be able to post as that Meetup.com user to that Group for the Venue selected.

Step 1: Download all files as a ZIP.
Step 2: Upload to WordPress as a plugin.
Step 3: Login to Meetup.com.
Step 4: Navigate here and grab your API key: https://secure.meetup.com/meetup_api/key/
Step 5: Grab your Group ID from the URL (such as Mobile-WordPress-Development-Meetup )
Step 6: Grab your Venue ID: https://www.meetup.com/{EnterYourGroupIDHere}/manage/settings/venues/
Step 7: Enter that stuff from 4-6 here: http://{EnterYourWordPressDomainHere}/wp-admin/admin.php?page=meetup-general-settings
Step 8: Post Events to WP and watch them post to Meetup.com.
