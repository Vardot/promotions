<?php
/**
 * @file
 * vardot_promotions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function vardot_promotions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function vardot_promotions_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function vardot_promotions_image_default_styles() {
  $styles = array();

  // Exported image style: promotions-block.
  $styles['promotions-block'] = array(
    'name' => 'promotions-block',
    'effects' => array(
      112 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 259,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sme-promotions-content.
  $styles['sme-promotions-content'] = array(
    'name' => 'sme-promotions-content',
    'effects' => array(
      111 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 700,
          'height' => 90,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function vardot_promotions_node_info() {
  $items = array(
    'promotions' => array(
      'name' => t('Promotion'),
      'base' => 'node_content',
      'description' => t('A promotional content, mainly for SME section.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
