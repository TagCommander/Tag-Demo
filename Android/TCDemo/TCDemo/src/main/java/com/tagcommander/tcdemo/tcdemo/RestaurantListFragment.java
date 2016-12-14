/**
 * 
 */
package com.tagcommander.tcdemo.tcdemo;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.ListFragment;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.tagcommander.tcdemo.data.Restaurants;

/**
 * @author damien
 *
 */
public class RestaurantListFragment extends ListFragment
{
    @Override
	public void onActivityCreated(Bundle savedInstanceState)
	{
		super.onActivityCreated(savedInstanceState);
		setListAdapter(new ArrayAdapter<>(getActivity(), android.R.layout.simple_list_item_1, Restaurants.TITLES));
	}

	@Override
	public void onListItemClick(ListView l, View v, int position, long id)
    {
        Intent detail = new Intent(this.getActivity().getApplicationContext(), RestaurantDetail.class);
        detail.putExtra("ID", (int) id);
        startActivityForResult(detail, 1);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == 1)
        {
            if (resultCode == Activity.RESULT_OK)
            {
                Bundle bundle = data.getExtras();
                if (bundle != null)
                {
                    Double lat = bundle.getDouble("latitude");
                    Double lon = bundle.getDouble("longitude");

                    MainActivity main = (MainActivity) this.getActivity();
                    main.latitude = lat;
                    main.longitude = lon;

                    main.mViewPager.setCurrentItem(1);
                }
            }
        }
    }

	@Override
	public void onResume()
	{
		super.onResume();
	}

	@Override
	public void onPause()
	{
		super.onPause();
	}
}


