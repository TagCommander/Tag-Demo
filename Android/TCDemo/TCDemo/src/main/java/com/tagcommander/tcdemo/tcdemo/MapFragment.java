package com.tagcommander.tcdemo.tcdemo;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.support.v4.app.ActivityCompat;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.tagcommander.tcdemo.data.Restaurants;

import java.util.ArrayList;

public class MapFragment extends Fragment implements GoogleMap.OnMarkerClickListener, GoogleMap.OnCameraChangeListener, OnMapReadyCallback
{
    ArrayList<Marker> markers = new ArrayList<>();
    GoogleMap googleMap;

    @Override
    public void onActivityCreated(Bundle savedInstanceState)
    {
        super.onActivityCreated(savedInstanceState);
    }

    @Override
    public void onMapReady(final GoogleMap googleMap)
    {
        if (this.googleMap == null)
        {
            this.googleMap = googleMap;
        }

        if (Build.VERSION.SDK_INT < 23 ||
                ActivityCompat.checkSelfPermission(getContext().getApplicationContext(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED)
        {
            googleMap.setMyLocationEnabled(true);
            googleMap.moveCamera(CameraUpdateFactory.zoomTo(16));
            googleMap.setOnCameraChangeListener(this);

            for (int i = 0; i < Restaurants.LATITUDES.length; ++i)
            {
                LatLng latLng = new LatLng(Restaurants.LATITUDES[i], Restaurants.LONGITUDES[i]);
                markers.add(googleMap.addMarker(new MarkerOptions().position(latLng).title(Restaurants.TITLES[i])));
                googleMap.setOnMarkerClickListener(this);
            }
        }
    }

	@Override
	public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState)
	{
        View rootView = inflater.inflate(R.layout.fragment_map, container, false);

        if (Build.VERSION.SDK_INT < 23 ||
                ActivityCompat.checkSelfPermission(getContext().getApplicationContext(), Manifest.permission.ACCESS_FINE_LOCATION) == PackageManager.PERMISSION_GRANTED)
        {
            com.google.android.gms.maps.MapFragment fm = (com.google.android.gms.maps.MapFragment) getActivity().getFragmentManager().findFragmentById(R.id.map);
            fm.getMapAsync(this);
        }

        return rootView;
	}

	@Override
    public void onResume()
	{
        LatLng latLng = new LatLng(48.8567, 2.3508);
        MainActivity main = (MainActivity) this.getActivity();
        if (main.longitude != 0.0 && main.latitude != 0.0)
        {
            latLng = new LatLng(main.latitude, main.longitude);

            for (int i = 0; i < Restaurants.LATITUDES.length; ++i)
            {
                if (Restaurants.LATITUDES[i].equals(main.latitude) && Restaurants.LONGITUDES[i].equals(main.longitude))
                {
                    markers.get(i).showInfoWindow();
                }
            }
        }

        if (this.googleMap != null)
        {
            this.googleMap.moveCamera(CameraUpdateFactory.newLatLng(latLng));
        }

        super.onResume();
    }

    @Override
    public void onPause()
    {
      super.onPause();
    }

    @Override
    public boolean onMarkerClick(Marker marker)
    {
        int id = 0;
        String title = marker.getTitle();
        for (int i = 0; i < Restaurants.TITLES.length; ++i)
        {
            if (Restaurants.TITLES[i].equals(title))
            {
                id = i;
                break;
            }
        }

        TagCommanderExample.sharedTagManager().SendClickEvent(TagCommanderExample.buildPageName("Map", "#restaurant_name#", "--detail", ""),
                "click");

        Intent detail = new Intent(this.getActivity().getApplicationContext(), RestaurantDetail.class);
        detail.putExtra("ID", id);
        startActivity(detail);
        return true;
    }

    @Override
    public void onCameraChange(CameraPosition cameraPosition)
    {
        MainActivity main = (MainActivity) this.getActivity();
        if (main != null)
        {
            main.longitude = cameraPosition.target.longitude;
            main.latitude = cameraPosition.target.latitude;
        }
    }
}
