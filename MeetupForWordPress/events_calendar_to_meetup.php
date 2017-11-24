<?php
/*
Plugin Name: The Events Calendar - Meetup.com Extension 
Plugin URI: https://knoxweb.com/ 
Description: 3rd party extension for Modern Tribe's The Events Calendar that allows autoposting Events to a Meetup.com Group on behalf of a specified Meetup.com organizer.
Version:     1.0
Author:      Knoxweb.com
Author URI:  https://knoxweb.com/ 
Domain Path: /languages
License:     GPL2
 
The Events Calendar - Meetup.com Extension is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
any later version.
 
The Events Calendar - Meetup.com Extension is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with The Events Calendar - Meetup.com Extension.
*/
/**
 * custom option and settings
 */

function meetup_settings_init() 
{
    // register a new setting for "Meetup setting page" page
    register_setting( 'meetup', 'meetup_options' ); 
}
/**
 * register our meetup_settings_init to the admin_init action hook
 */
add_action( 'admin_init', 'meetup_settings_init' );
 
// activation of plugin file
function meetup_css_reg() 
{
    wp_enqueue_style( 'meetup-css', plugins_url( '/meetup-css.css', __FILE__ ) );
}

add_action('admin_print_styles', 'meetup_css_reg');

/**
 * top level menu
 */
function meetup_options_page() {
     // add top level menu page
     add_menu_page(
     'meetup',
     'Meetup.com Options',
     'manage_options',
     'meetup',
     'meetup_options_page_html'
     );
}
 
/**
 * register our wporg_options_page to the admin_menu action hook
 */
add_action( 'admin_menu', 'meetup_options_page' );
 
/**
 * top level menu:
 * callback functions
 */
    function meetup_options_page_html() {
     // check user capabilities
         if ( ! current_user_can( 'manage_options' ) ) {
     return;
     }
 
    if ( isset( $_POST['save_setting'] ) ) {
         // add settings saved message with the class of "updated"
        update_option('meetup_membership_id',$_POST['member_id_meet_up']);
        update_option('meetup_group',$_POST['meetup_group_id']);
        update_option('meetup_venue_id',$_POST['meetup_venue_id']);
        update_option('meetup_venue_name',$_POST['meetup_venue_name']);
        add_settings_error( 'meetup_messages', 'meetup_message', __( 'Settings Saved', 'meetup' ), 'updated' );
    }
 
    // show error/update messages
    settings_errors( 'meetup_messages' );
    ?>
    <div class="wrap form_meetup">
      <h1>Settings for Meetup.com Sync</h1>
      <?php 
      $member_id = get_option('meetup_membership_id');
      $group_id = get_option('meetup_group');
      $venue_id = get_option('meetup_venue_id');
      $venue_name = get_option('meetup_venue_name');
      ?>
      <form action="" method="post" class="form-inline">
          <div class="meetup_label_setting">  
          <a href="https://secure.meetup.com/meetup_api/key/" target="_blank"><label for "Member_id"> Meetup.com User API Key: </label></a>
        </div>  
        <div class="meetup_fields">
          <input type = "text" class="meetup_member_id" name ="member_id_meet_up" value="<?php echo $member_id;?>" required>
        </div>  
        <div class ="field_description">
            <h4>Make sure that the user has permission on Meetup.com to create evens for the below group and please note that anyone on your website who can publish WordPress Events will be able to publish Meetup.com as this Meetup.com user!</h4>
        </div>
               <br>
        <div class="meetup_label_setting">
          <label for "group"> Meetup.com Group ID: </label>
        </div>
        <div class="meetup_fields">   
          <input type = "text" class= "meetup_group_id" name = "meetup_group_id" value="<?php echo $group_id;?>" required>
        </div>  
        <div class ="field_description">
            <h4>Enter the human readable slug from the group's main URL such as Knoxville-Makerspaces-Meetup.</h4>
        </div>
        <div class="meetup_label_setting">
          <label for "group"> Venue Id :</label>
        </div>
        <div class="meetup_fields">   
          <input type = "text" class="meetup_venue_id" name = "meetup_venue_id" value="<?php echo $venue_id;?>" required>
        </div>  
        <div class="meetup_label_setting">
          <label for "group"> Venue Name : </label>
        </div>
        <div class="meetup_fields">   
          <input type = "text" class="meetup_venue_name" name = "meetup_venue_name" value="<?php echo $venue_name;?>" required>
        </div>
          <input type = "submit" class ="button button-primary"  value = "Save setting" name = "save_setting">
      </form>
    </div>
 <?php
}

//meta box for meetup for tribe_events  
 function register_meta_tribe_events() {
    add_meta_box( 'tribe_events_meta', __( 'Meetup.com Sync', 'textdomain' ), 'tribe_events_fields_meta', 'tribe_events' );
}
add_action('add_meta_boxes', 'register_meta_tribe_events' );

// call back function for print all value in metabox
function tribe_events_fields_meta( $post ) {
    // display fields
    $post_id = $post->ID;
    $meetup_sync = get_post_meta($post_id,'meetup_sync',true);
    ?>
    <input type="checkbox" name="meetup_checked" value="meetup_sync_checked" <?php if ( "meetup_sync_checked" == $meetup_sync ) echo 'checked="checked"'; ?> /> Disable posting this event to Meetup.com? <br><br>
    <?php
    echo '<label for="price" style="width:150px; display:inline-block;">'. esc_html__('Venue ID', 'text-domain') .'</label>';
    $venue_id = get_option('meetup_venue_id');
    echo '<input type="text" name="venue_id" id="meetup_venue" class="meetup_venue" value="'. esc_attr($venue_id) .'" style="width:300px;" readonly/>';
    echo '<br><br>';
    echo '<label for="star_rating" style="width:150px; display:inline-block;">'. esc_html__('Venue Name', 'text-domain') .'</label>';
    $venue_name = get_option('meetup_venue_name');
    echo '<input type="text" name="venue_name" id="meetup_venue_name" class="meetup_venue_name" value="'. esc_attr($venue_name) .'" style="width:300px;" readonly/>';
}

//meta box for meetup for tribe_events  
function meetup_additional_info()
{
    add_meta_box( 'tribe_events_additional_info', __( 'Extra Details to Meetup.com', 'textdomain' ), 'additional_details_meetup', 'tribe_events' );
}
add_action('add_meta_boxes', 'meetup_additional_info' );
//call back function for addition info

function additional_details_meetup($post){
  $post_id = $post->ID;    
  $meetup_additional_info_check = get_post_meta($post_id,'meetup_additional_info_check',true);
  $Content = get_post_meta($post_id,'additional_info_meetup',true);
  ?>
  <h4>Check the checkbox below to add extra details to the bottom of the Meetup.com description. If you select this option, this Event's URL will appear below your additional information text.</h4>
  <input type="checkbox" id="additional_info_meetup_check" name="meetup_additional_info_check" value="meetup_additional_info_check" <?php if ( "meetup_additional_info_check" == $meetup_additional_info_check ) echo 'checked="checked"'; ?> /> Add aditional info <br><br>
  <div id="additional_info">
  <?php wp_editor($Content,'additional_info_meetup',$settings);?> 
  </div>
  <?php
}
//function for all events 
function event_connect_meetup($end_point,$data,$type)
{
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL,$end_point);    
    curl_setopt($ch, CURLOPT_POST, 1);                                                               
    curl_setopt($ch, CURLOPT_CUSTOMREQUEST,$type);                                                                     
    curl_setopt($ch, CURLOPT_POSTFIELDS,$data); 
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    $response = curl_exec($ch);
    curl_close($ch);
    return $response;
}
// function for save post
function event_data_after_submit($post_id) {
        global $post; 
        $post_type = get_post_type($post_id);
        $myPost = get_post($post_id);
       
        if ("tribe_events" != $post_type )
            return;
            $title = $_POST['post_title'];
            $content = $_POST['content'];
            $venue_id = sanitize_key($_POST['venue_id']);
            $event_data = $_POST['EventStartDate'].' '.$_POST['EventStartTime'];
            $event_time_stamp = strtotime("$event_data")*1000;
            $event_end_data = $_POST['EventEndDate'].' '.$_POST['EventEndTime'];
            $event_time_end_stamp = strtotime("$event_end_data")*1000;
            $duration=$event_time_end_stamp-$event_time_stamp;
            $member_id = sanitize_key(get_option('meetup_membership_id'));
            $group_slug = esc_html(get_option('meetup_group'));
            $meetup_post_id = sanitize_key(get_post_meta($post_id,'meetup_postid',true)); 
            $meetup_sync_check = get_post_meta($post_id,'meetup_sync',true);
           
        if(isset($_POST['meetup_checked']))
        {
            update_post_meta($post_id,'meetup_sync','meetup_sync_checked');   
        }
        else
        {
            delete_post_meta($post_id,'meetup_sync');
        }
        if(isset($_POST['meetup_additional_info_check']))
        {
            $post_link = get_permalink($post_id);
            $title = get_the_title($post_id);
            update_post_meta($post_id,'meetup_additional_info_check','meetup_additional_info_check'); 
            update_post_meta($post_id,'additional_info_meetup',$_POST['additional_info_meetup']);
            $content = $content."\n\n\n\n".stripslashes($_POST['additional_info_meetup'])."\n\n\n\nYou can register here:\n\n\n\n<a href=\"".$post_link."\" target=\"_blank\">".$title."</a>";
        }
        else
        {
            delete_post_meta($post_id,'meetup_additional_info_check');
        }
             
          
        if(isset($_POST['meetup_checked']) && $meetup_post_id!='')
        {
            $end_point  = "api.meetup.com/".$group_slug."/events/".$meetup_post_id."/?key=$member_id";
            $type = "DELETE";
            $data = "remove_from_calendar=true";
            $res = event_connect_meetup($end_point,$data,$type);
            $response_array = json_decode($res,true);
                if (array_key_exists("errors",$response_array))
                {
                    wp_redirect(admin_url('post.php?post='.$post_id.'&action=edit&meetup=error_active'));
                    exit;
                }
            //event_connect_meetup($end_point,$data,$type,$response);
            delete_post_meta($post_id,'meetup_postid', $meetup_post_id);   
        }
        else
        {
            if( $myPost->post_modified_gmt == $myPost->post_date_gmt && $meetup_sync_check=='')
             {

                $end_point  = "api.meetup.com/".$group_slug."/events?key=$member_id";
                $data = "name=$title&description=$content&venue_id=$venue_id&time=$event_time_stamp&duration=$duration&announce=true";
                $type = "POST";
                $res = event_connect_meetup($end_point,$data,$type);
                //event_connect_meetup($end_point,$data,$type,$response);
                $response_array = json_decode($res,true);
                update_post_meta($post_id,'meetup_response',$res);
                if (array_key_exists("errors",$response_array))
                {
                    wp_redirect(admin_url('post.php?post='.$post_id.'&action=edit&meetup=error_active'));
                    exit;              
                }
                else
                {
                    $meetup_postid = $response_array['id'];
                    update_post_meta($post_id,'meetup_postid',$meetup_postid);
                } 

            }
            else
            {
                if($meetup_post_id=='' && $meetup_sync_check==''){
                      //condition for if meetup_post_id is blank and checkbox is unchecked then create new event.
                    $end_point  = "api.meetup.com/".$group_slug."/events?key=$member_id";
                    $data = "name=$title&description=$content&venue_id=$venue_id&time=$event_time_stamp&duration=$duration&announce=true";
                    $type = "POST";
                    $res = event_connect_meetup($end_point,$data,$type);
                    $response_array = json_decode($res,true);
                   //event_connect_meetup($end_point,$data,$type,$response);
                    update_post_meta($post_id,'meetup_response',$res);
                    if (array_key_exists("errors",$response_array))
                    {
                        wp_redirect(admin_url('post.php?post='.$post_id.'&action=edit&meetup=error_active'));
                        exit;
                    }
                    else
                    {
                        $meetup_postid = $response_array['id'];
                        update_post_meta($post_id,'meetup_postid',$meetup_postid);
                    } 
                }  
                else
                {
                        //if meetup_id_is available then create 
                    $end_point  = "api.meetup.com/".$group_slug."/events/".$meetup_post_id."/?key=$member_id";
                    $data = "name=$title&description=$content&venue_id=$venue_id&time=$event_time_stamp&duration=$duration";
                    $type = "PATCH";
                    $res = event_connect_meetup($end_point,$data,$type);
                    $response_array = json_decode($res,true);
                    //event_connect_meetup($end_point,$data,$type,$response);
                    update_post_meta($post_id,'meetup_response',$res);
                    if (array_key_exists("errors",$response_array))
                    {
                       wp_redirect(admin_url('post.php?post='.$post_id.'&action=edit&meetup=error_active'));
                       exit;
                    }
                }  
            }
        }
    }
if(isset($_POST['venue_id'])){
add_action('save_post', 'event_data_after_submit' );
}
//script for shpw hide additional info text editor
add_action('admin_footer', 'my_admin_add_js');
function my_admin_add_js() {?>
  <script>
    jQuery( document ).ready(function() {
        function handle_additional_info() {
             if(jQuery('#additional_info_meetup_check').is(":checked")) {
               jQuery("#additional_info").show();
            }
            else{
               jQuery("#additional_info").hide(); 
            }
        }
         jQuery('#additional_info_meetup_check').live('change',handle_additional_info);
         handle_additional_info();
    });
  </script>
<?php
    
}

//function for display error 
add_action( 'admin_head','error_occurs_while_posting');
function error_occurs_while_posting(){
    $meetup = $_GET["meetup"];
    if($meetup == "error_active"){
    ?>
     <div class="notice error my-acf-notice is-dismissible" >
        <p><?php _e('There are some errors while creating or updating event on Meetup.com. So we are unable to post this event on meetup.com.'); ?></p>
    </div>
   <?php
    }
}
